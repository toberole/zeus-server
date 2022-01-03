#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

void start_server()
{
    //  int socket(int domain, int type, int protocol);
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
    {
        printf("create socket error\n");
        return;
    }

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(sockaddr_in));
    printf("bind ret: %d\n", ret);

    ret = listen(listen_fd, 1024);
    printf("listen ret: %d\n", ret);

    int clientfd = accept(listen_fd, nullptr, nullptr);
    uint8_t buf[1024] = {0};
    recv(clientfd, buf, 1024, 0);
    printf("client msg: %s\n", buf);
    close(clientfd);
}

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");
    start_server();
    return 0;
}
