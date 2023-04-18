#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9000); 

    if (connect(client, (struct sockaddr *)&addr, sizeof(addr))) {
        perror("connect() failed");
        return 1;
    }

    // nhap du lieu va tao buffer chua du lieu can gui
    char buf[256];
    int pos = 0;

    char computer_name[16];
    printf("nhao ten may tinh: ");
    scanf("%s", computer_name);


    int num_drives;
    printf("nhap so o dia");
    scanf("%d", &num_drives);

    char drive_letter;
    unsigned short drive_size;

    for (int i = 1; i < num_drives; i++){
        printf("Nhap ky tu: ");
        scanf("%c", &drive_letter);



        printf("nhao kich thuoc: ");
        scanf("%hd", &drive_size);
    }

    printf("Buffer size: %d \n", pos);












    // int n;
    // char odia[9];
    // char buf[256];

    // while (1)
    // {
    //     printf("Nhap ten may tinh: ");
    //     scanf("%s", mt);

    //     getchar();

    //     printf("Nhap so o dia: ");
    //     fgets(n, sizeof(n), stdin);

    //     for ( int i = 0; i < n; i++)
    //     {
    //         scanf("%s",odia);
    //         strcat(buf,odia);
    //     }

    //     send(client, buf, strlen(buf), 0);
    // }

    // Ket thuc, dong socket
    close(client);

    return 0;
}