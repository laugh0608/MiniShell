#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  //fd就是文件描述符
  //打开文件
  int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
  char buf[1024] = "QiDian-test";
  //写文件
  int ret = write(fd, buf, strlen(buf));
  //printf("ret = %d\n", ret);
  //控制文件指针
  lseek(fd, 0, SEEK_SET);
  memset(buf, 0, 1024);
  //读文件
  ret = read(fd, buf, 1024);
  printf("ret = %d\n", ret);
  printf("buf = %s\n", buf);
  close(fd);
}
