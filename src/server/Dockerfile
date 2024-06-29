FROM nginx:latest
WORKDIR /home
COPY ./server.c /home/
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
RUN apt update && apt install -y gcc g++ make spawn-fcgi libfcgi-dev curl && \
    rm -rf /var/lib/apt/lists/* && \
    gcc -o /home/server /home/server.c -lfcgi && \
    useradd -m -d /home myuser && \
    chown -R myuser:myuser /etc/nginx/nginx.conf; \
    chown -R myuser:myuser /var/cache/nginx; \
    chown -R myuser:myuser /home/; \
    touch /var/run/nginx.pid && chown -R myuser:myuser /var/run/nginx.pid; \
    chown -R myuser:myuser /home && \
    chmod u-s /usr/bin/chfn && \
    chmod g-s /usr/sbin/unix_chkpwd && \
    chmod g-s /usr/bin/expiry && \
    chmod u-s /usr/bin/umount && \
    chmod u-s /usr/bin/su && \
    chmod u-s /usr/bin/passwd && \
    chmod g-s /usr/bin/chage && \
    chmod u-s /usr/bin/chsh && \
    chmod u-s /usr/bin/mount && \
    chmod u-s /usr/bin/newgrp && \
    chmod u-s /usr/bin/gpasswd
USER myuser
HEALTHCHECK --interval=30s --timeout=5s --start-period=10s CMD curl -f http://localhost:81/ || exit 1
CMD spawn-fcgi -p 8080 /home/server && nginx -g 'daemon off;'