#include <iostream>
#include <string>
#include <sys/stat.h>
#include <bits/stdc++.h>
#include <exception>
using namespace std;
char str1[10];
char str2[10];
int server_ver=0;
int local_ver=0;
char pid[500];
string pid1;
int length;
int posf;
int pos;

int main()
	{
system("rm current.txt");
system("clear");
system("curl -LO https://uberkill.cc/patcher/current.txt");
system("clear");
FILE * dir;
dir = fopen("version.txt", "r");
if(errno==2)
    return 0;
fclose (dir);
ifstream in1("current.txt");
    while(in1)
        {
        in1.getline(str1, 10);
        if(in1)
            sscanf(str1, "%d", &server_ver);
        }  
in1.close();
ifstream in2("version.txt");
while(in2)
        {
        in2.getline(str2, 10);
        if(in2)            
            sscanf(str2, "%d", &local_ver);       
        }
in2.close();
if(server_ver>local_ver)
	  {
	system("rm output.txt");	
	system("ps -aux | grep UberStrike > output.txt");
    system("clear");
	ifstream task("output.txt");
		while(task)
		{
		task.getline(pid, 500);
		if(task)
			pid1=pid;
		}
	task.close();
	pos = pid1.find(" ");
	for(int i=pos;pid1[i]==' ';i++)
        pos=i;
	pos++;
	for(int j=pos;pid1[j]!=' ';j++)
		posf=j;
	posf++;
	pid1=pid1.substr(pos,length);
	system(("kill -9 "+pid1).c_str());
	system("rm output.txt");
    system("rm -rf patch");
    system("rm macpatch.zip");
    system("clear");
    cout<<endl<<"Server Version: "<<server_ver<<endl;
    cout<<endl<<"Local Version: "<<local_ver<<endl;
    cout<<"Updating......"<<endl<<endl<<endl;
    system("curl -LO https://uberkill.cc/patchfiles/macpatch.zip");
    system("unzip macpatch.zip");
    system("//bin//cp patch//uberdaemon");
	system("chmod +x uberdaemon");
	system("//bin//cp -a patch//Data//. Uberstrike.app//Contents//Data");
    system("clear");
    system("del macpatch.zip");
    system("rm -rf patch");
    system("rm version.txt");
    system("mv current.txt version.txt");
	system("clear");
    cout<<"Launching Game...."<<endl;
    system("open steam://rungameid/291210");
    return 0;
	  }
else system("rm current.txt");
    return 0;
	}
