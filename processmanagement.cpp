#include <iostream>
#include <unistd.h>    // For fork(), getpid(), execl()
#include <sys/wait.h>  // For wait()

using namespace std;

void processManagement() {
    cout << "\n===== PROCESS MANAGEMENT =====\n";
    pid_t pid;

    // Create Child Process
    pid = fork();

    if (pid < 0) {
        cout << "Fork failed!\n";
        return;
    } 
    else if (pid == 0) {
        // Child Process
        cout << "Child Process Running\n";
        cout << "Child PID: " << getpid() << endl;

        // Execute Linux command (ls)
        cout << "Executing 'ls' command via child...\n";
        execl("/bin/ls", "ls", NULL);

        // If execl fails
        cout << "Execution failed!\n";
    } 
    else {
        // Parent Process
        wait(NULL); // Wait for child to finish
        cout << "Parent Process Running\n";
        cout << "Parent PID: " << getpid() << endl;
    }
}

int main() {
    processManagement();
    return 0;
}
