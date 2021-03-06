//_stat函数用来获取指定路径的文件或者文件夹的信息。
/* 需要包含de头文件
#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *_Filename, struct stat *_Stat);    //文件或者文件夹的路径
返回值：
正确——返回0
错误——返回-1，具体错误码保存在errno中

//prototype,原型
_stat结构体是文件（夹）信息的结构体
struct stat
{
    dev_t       st_dev;     // ID of device containing file -文件所在设备的ID
    ino_t       st_ino;     // inode number -inode节点号
    mode_t      st_mode;    // protection -保护模式
    nlink_t     st_nlink;   // number of hard links -链向此文件的连接数(硬连接)
    uid_t       st_uid;     // user ID of owner -user id
    gid_t       st_gid;     // group ID of owner - group id
    dev_t       st_rdev;    // device ID (if special file) -设备号，针对设备文件
    off_t       st_size;    // total size, in bytes -文件大小，字节为单位
    blksize_t   st_blksize; // blocksize for filesystem I/O -系统块的大小
    blkcnt_t    st_blocks;  // number of blocks allocated -文件所占块数
    time_t      st_atime;   // time of last access -最近存取时间
    time_t      st_mtime;   // time of last modification -最近修改时间
    time_t      st_ctime;   // time of last status change -
};
*/

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>

int main_struct_stat()
{
    struct stat buf;
    int ret;
    //std::cout<<system("dir")<<std::endl;
    ret = stat("configFile", &buf);
    if (ret == 0)
    {
        std::cout<<"size of file in bytes: "<<buf.st_size<<std::endl;
    }
    else {
        perror("Failed ");
    }

    return 0;
}
