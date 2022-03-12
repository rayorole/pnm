#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc == 2) {
    if (0 == strcmp(argv[1], "start")) {
      if (geteuid() != 0) {
        printf("error: you have no root priviliges, use pnm with sudo instead");
      } else {
        system("systemctl start nginx && systemctl start mysql && systemctl "
               "start php-fpm");
        printf("[*] Succesfully started MySQL, PHP and nginx");
      }
    } else if (0 == strcmp(argv[1], "stop")) {
      if (geteuid() != 0) {
        printf("error: you have no root priviliges, use pnm with sudo instead");
      } else {
        system("systemctl stop nginx && systemctl stop mysql && systemctl stop "
               "php-fpm");
        printf("[*] Succesfully terminated MySQL, PHP and nginx");
      }
    } else if (0 == strcmp(argv[1], "restart")) {
      if (geteuid() != 0) {
        printf("error: you have no root priviliges, use pnm with sudo instead");
      } else {
        system(
            "systemctl restart nginx && systemctl restart mysql && systemctl "
            "restart php-fpm");
        printf("[*] Succesfully restarted MySQL, PHP and nginx");
      }
    }

    else if (0 == strcmp(argv[1], "install")) {
      if (geteuid() != 0) {
        printf("error: you have no root priviliges, use pnm with sudo instead");
      } else {
        char mysql_user[100];

        printf("[*] Installing MySQL, PHP and nginx services \n");

        printf("Enter a mysql database username: ");
        scanf("%s", mysql_user);
        printf("%s", mysql_user);
      }
    }

    else if (0 == strcmp(argv[1], "version")) {
      printf("pnm: v.1.0.3");
    }

    else if (0 == strcmp(argv[1], "help")) {
      printf("   >=== Made with ❤️ by Ray Orolé ===< \n\n");
      printf("   install        Install and configure Nginx, PHP and MySQL "
             "techstack \n");
      printf("   start          Start Nginx, PHP and MySQL services \n");
      printf("   restart        Restart Nginx, PHP and MySQL services \n");
      printf("   stop           Terminate Nginx, PHP and MySQL services \n\n");
      printf("   (pnm requires root permissions)");
    } else {
      printf("unknown argument: %s \n", argv[1]);
      printf("usage: pnm help");
    }
  } else if (argc > 2) {
    printf("Too many arguments supplied. See 'pnm help'\n");
  } else {
    printf("   >=== Made with ❤️ by Ray Orolé ===< \n\n");
    printf("   install        Install and configure Nginx, PHP and MySQL "
           "techstack \n");
    printf("   start          Start Nginx, PHP and MySQL services \n");
    printf("   restart        Restart Nginx, PHP and MySQL services \n");
    printf("   stop           Terminate Nginx, PHP and MySQL services \n\n");
    printf("   (pnm requires root permissions)");
  }
}