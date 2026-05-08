#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <unistd.h>
using namespace std;

int main(){

    int fd;
    char buffer[100];

    // 1. Open and Create the file
    fd = open("data.txt", O_CREAT | O_RDWR, 0644);
    if(fd<0){
        cout << "File creation failed" << endl;
        return 1;
    }
    cout << "File creation successfull" << endl;

    //2. Write into file
    char msg[] = "Welcome to Windows";
    write(fd, msg, strlen(msg));
    cout << "Data written successfull" << endl;

    //3. Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // 4. read File contents
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    cout << "File Contents:" << buffer << endl;

    //5. Close file
    close(fd);
    cout << "File closed Succesfully" << endl;

    //6. Rename File
    rename("data.txt", "test.txt");

    //7. Get file information
    struct stat file;
    stat("test.txt", &file);
    cout << "File size:" << file.st_size << "bytes" << endl;
    cout << "File Permissions:" << file.st_mode << endl;

    //8. Change file permissions
    chmod("test.txt", 0744);
    cout << "file permissions changed successfully" << endl;

    //9. Delete file
    unlink("test.txt");
    cout << "File Deleted Successfully" << endl;

    return 0;
}

