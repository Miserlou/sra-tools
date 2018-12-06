#include <kapp/main.h> /* KMain */
#include "fcgi_stdio.h"
rc_t CC KMain(int argc, char * argv[]) {
    int count = 0;
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n"
            "\r\n"
            "<title>FastCGI echo</title>"
            "<h1>FastCGI echo</h1>\n"
            "Request number %d\n", ++count);
    }
    /*streambuf * cin_streambuf = std::cin.rdbuf();
    streambuf * cout_streambuf = std::cout.rdbuf();
    streambuf * cerr_streambuf = std::cerr.rdbuf();
    FCGX_Request request;
    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);
    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);
    }*/
    return 0;
}
