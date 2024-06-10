#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  // Deklarasi variabel
  int jumlahChildProcess;
  pid_t childPid;

  // Input jumlah child process
  cout << "Masukkan jumlah child process: ";
  cin >> jumlahChildProcess;

  // Forking untuk membuat child process
  for (int i = 0; i < jumlahChildProcess; i++) {
    childPid = fork();

    // Cek status forking
    if (childPid == 0) { // Child process
      cout << "Child process dengan PID: " << getpid() << endl;
      exit(0); // Keluar dari child process
    } else if (childPid > 0) { // Parent process
      cout << "Parent process membuat child process dengan PID: " << childPid << endl;
    } else { // Error forking
      cout << "Gagal membuat child process" << endl;
    }
  }

  return 0;
}
