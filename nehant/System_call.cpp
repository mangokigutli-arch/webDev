#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

void fileManagement()
{
    cout << "\n FILE MANAGEMENT\n";

    int fd;

    fd = creat("file_demo.txt", 0777);

    if(fd < 0)
    {
        cout << "File Not Created!\n";
        return;
    }

    cout << "File Created.\n";

    const char *data = "Linux System Calls!";
    write(fd, data, strlen(data));

    cout << "Data written successfully.\n";

    close(fd);

    fd = open("file_demo.txt", O_RDONLY);

    char buffer[100];
    int bytes = read(fd, buffer, sizeof(buffer));
    buffer[bytes] = '\0';

    cout << "Data read from file: " << buffer << endl;

    close(fd);

    unlink("file_demo.txt");

    cout << "File deleted.\n";
}

void directoryManagement()
{
    cout << "\n DIRECTORY MANAGEMENT\n";

    mkdir("MyDirectory", 0777);
    cout << "Directory created.\n";

    chdir("MyDirectory");
    cout << "Changed to MyDir.\n";

    char path[100];
    getcwd(path, sizeof(path));

    cout << "Current Directory Path: " << path << endl;

    chdir("..");

    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");

    cout << "\nDirectory Contents:\n";

    while((entry = readdir(dir)) != NULL)
    {
        cout << entry->d_name << endl;
    }

    closedir(dir);

    rmdir("MyDir");
    cout << "Directory removed.\n";
}

void processManagement()
{
    cout << "\n PROCESS MANAGEMENT\n";

    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        cout << "Fork failed!\n";
        return;
    }
    else if(pid == 0)
    {
        cout << "Child Process Running\n";
        cout << "Child PID: " << getpid() << endl;

        execl("/bin/ls", "ls", NULL);

        cout << "Execution failed!\n";
    }
    else
    {
        wait(NULL);

        cout << "Parent Process Running\n";
        cout << "Parent PID: " << getpid() << endl;
    }
}

int main()
{
    int choice;

    cout << "\n LINUX SYSTEM CALLS\n";

    cout << "1. File Management\n";
    cout << "2. Directory Management\n";
    cout << "3. Process Management\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            fileManagement();
            break;

        case 2:
            directoryManagement();
            break;

        case 3:
            processManagement();
            break;

        default:
            cout << "Invalid Choice!\n";
    }

    cout << "\nProgram Completed.\n";

    return 0;
}