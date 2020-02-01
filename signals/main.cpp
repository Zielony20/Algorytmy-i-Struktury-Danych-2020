#include <iostream>
#include <csignal>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   exit(signum);  
}

int main () {
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   while(1) {
      cout << "Going to sleep...." << endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }

   return 0;
}
