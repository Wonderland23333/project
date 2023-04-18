/*
 * data_transfer.c
 *
 * created: 2023/4/16
 *  author: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

#define EQUIPMENTNUM 20
#define BUFFERSIZE 1024
#define IPSTR      40
int main()
{
    int sd_sockt;
    int listen_fd,conn_fd;
    int rcv_size;
    char buf[BUFFERSIZE];
    char str[IPSTR];
    struct sockaddr_in server_addr,client_addr;
    
    bzero(&server_addr,sizeof(server_addr));//�ṹ������
    sd_sockt = socket(AF_INET,SOCK_STREAM,0);//����socket�׽���
    if(sd < 0 )
    {
        perror("socket()");
        exit(1);
    }
    //sockaddr_in�ṹ���ʼ��
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.sa_addr=htonl(INADDR_ANY);
    server_addr.sin_port = htons(80);
    //����listen_fd�����׽���
    listen_fd = listen(sd_socket,EQUIPMENTNUM);
    if(listen_fd < 0 )
    {
        perror("listen()");
        exit(1);
    }
    while(1)
    {
        conn_fd = accept(listen_fd,(void *)&client_addr,sizeof(client_addr));
        rcv_size = rcv(conn_fd,buf,BUFFERSIZE,0);
        printf("received from %s at PORT: %d",inet_ntop(AF_INET,&client_addr.sin_addr,str,sizeof(str)),ntohs(client_addr.sin_port));
        doit(&buf);//���ݴ���
        close(conn_fd);
    }
    send();
    close(sd_socket);
    return 0;
}
void doit(char *buf)
{

}



