#include<iostream>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
using namespace std;

int main(){
    char path[200];
    struct dirent *entry;

    //1. Create the main directory
    int Dir = mkdir("Mydirectory", 0755);
    if(Dir<0){
        cout << "Directory Creation Failed" << endl;
        return 1;
    }
    cout << "Directory Created Successfully" << endl;

    //2.Create subdirectory
    int subdir = mkdir("Mydirectory/SubDirectory", 0744);
    if(subdir<0){
        cout << "Subdirectory Creation failed" << endl;
        return 1;
    }
    cout << "subdirectory created successfully" << endl;

    //3. change directory path
    int pat = chdir("Mydirectory");
    if(pat<0){
        cout << "Directory changed failed" << endl;
        return 1;
    }
    cout << "Directory changed successfully" << endl;

    //4. get current working directory path
    getcwd(path, sizeof(path));
    cout << path;

    //5. open directory
    DIR *dir = opendir(".");
    if(dir==NULL){
        cout << "Directory opened failed" << endl;
        return 1;
    }
    cout << "Directory opened successfully" << endl;

    //6. Close directory
    int clo = closedir(dir);
    if(clo<0){
        cout << "Directory closing failed" << endl;
        return 1;
    }
    cout << "Directory closed" << endl;

    //7. go back to parent diretory
    chdir("..");
    cout << path;

    //8. Rename the directory
    rename("Mydirectory", "Mydir");
    cout << "Directory Name changed" << endl;

    //9. rename sub directory
    rename("Mydir/SubDirectory", "Subdir");
    cout << "Sub directory Name changed" << endl;

    //10. remove subdirectory
    rmdir("Mydir/Subdir");
    cout << "deleted sub directory" << endl;
    cout << path;

    //11. Remove main directory
    rmdir("Mydir");
    cout << "deleted Main directory" << endl;
    cout << path;

    return 0;
}
