#include <fcgi_stdio.h>

int main() {
  FCGX_Request request;

  FCGX_Init();
  FCGX_InitRequest(&request, 0, 0);

  while (FCGX_Accept_r(&request) == 0) {
    FCGX_FPrintF(request.out, "Content-Type: text/html\r\n\r\n");
    FCGX_FPrintF(request.out, "<html><head><title>Hello</title></head>");
    FCGX_FPrintF(request.out, "<body><h1>Hello World!</h1></body></html>");
    FCGX_Finish_r(&request);
  }

  return 0;
}
