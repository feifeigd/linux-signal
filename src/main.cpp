
#include <unistd.h>
#include <signal.h>

#include <cstdio>
#include <iostream>

using namespace std;

void sigroutine(int dunno);
bool g_run = true;

int main(){
	printf("process id is %d\n", getpid());
	signal(SIGHUP, sigroutine);
	signal(SIGINT, sigroutine);
	signal(SIGQUIT, sigroutine);
	signal(SIGTERM, sigroutine);
	//signal(SIGKILL, sigroutine);	// 无法捕获

	//kill -HUP 进程号 //向进程发送SIGHUP信号
	// kill -9 进程号 //向进程发送SIGKILL信号，终止进程

	while(g_run)
		sleep(10);

	cout << "process end." << endl;
	return 0;
}

void sigroutine(int dunno){
	switch(dunno){
	case SIGHUP:
		printf("Get a signal -- SIGHUP");
		break;
	case SIGINT:	// Ctrl+C
		printf("Get a signal -- SIGINT");
		g_run = false;
		break;
	case SIGQUIT:	// Ctrl+\ 
		printf("Get a signal -- SIGQUIT");
		break;
	case SIGTERM:	// kill 进程号
		printf("Get a signal -- SIGTERM");
		g_run = false;
		break;
	default:
		printf("Get a signal -- %d", dunno);
		break;
	}
	printf("\n");
}
