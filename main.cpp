/*
 * @Author: Caviar-X、ExecuteIf
 * @Date: 2020-11-17 20:35:00
 * @LastEditTime: 2020-11-29 11:21:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \node.jv\main.cpp
 */
//PLEASE READ THIS WITH UTF-8

//#include "NodeJv.hpp"

#include <bits/stdc++.h>
#include <Windows.h>
#undef pascal
#define color(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a)
#define _DEBUG_

//预处理器区
using namespace std;
//函数声明区
/**
 * @description:  Dispatch The console Message
 * @param arg
 */
void Dispatch_message(string arg);
/**
 * @description: Display The Welcome Message
 */
void welcome();
/**
 * @description: Display an error
 * @param err_code
 */
void error(errno_t err_code);
//全局函数区
char op = '>';
string arg_user;
void *variable[114514];
char tmp[1001]="\0";
int tmpint=0;

//main()
int main(int argc, char *argv[])
{
	system("chcp 65001>nul");
	ZeroMemory(variable, sizeof(variable));
	welcome();
	while (1)
	{
		printf("%c ", op);
		getline(cin, arg_user);
		Dispatch_message(arg_user);
	}
	return 0;
}

HWND hwnd;

//函数实现区
void error(errno_t err_code)
{
	hwnd=FindWindow("ConsoleWindowClass",NULL);
	color(4);
	switch (err_code)
	{
		case 0:
		{
			//没有分号
			printf("Error: expected ';' was not found on this statement\n");
			break;
		}
		case 1:
		{
			//括号配对不正确
			printf("Error: expected ')' was not found on this statement\n");
			break;
		}
		case 2:
		{
			//""匹配不正确
			printf("Error: expected ' \" ' was not found on this statement\n");
			break;
		}
		case 3:
		{  //空字符串
			printf("Error: Empty string!\n");
			break;
		}
		case 4:
		{
			printf("Unkown experssion\n");
			break;
		}
		case 111:
		{  //未知函数/命令
			color(4);
			cout<<"Error: unknown function or command\n";
			color(7);
			break;
		}
		default:
		{
			if(hwnd)
			{
				ShowWindow(hwnd,SW_HIDE);
			}
			MessageBox(NULL,":(\nNodeJv Crashed!\n\nat jvav.nrror.info:\n\t315:212 Unknown Error Code\n\t921:73   No Answer\n\nIf problem still happen anyway,please contact to us:\nhttps://www.jvavexec.top/","NodeJv -- CrashHander",MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
			system(".\\bin\\ffplay .\\bin\\input.mp4 -fs");
			exit(0xc0000005);
		}
	}
	color(7);
}
void welcome()
{
	color(10);
	cout << "Welcome to Node.Jv!\n Type \"help\" for some help\n";
	color(7);
}
void Dispatch_message(string arg)
{
	if (arg == "")
		printf("underfined\n");
	else if (arg == "help")
	{
		color(11);

		printf("     |\\     |            |               ---------      (C) 2020                                          \n");
		printf("     | \\    |            |                   |                                                            \n");
		printf("     |  \\   |            |  ___              |                                                            \n");
		printf("     |   \\  |   /-\\   /--| /   \\             |   \\    /                                                \n");
		printf("     |    \\ |  |   | |   | |---              /    \\  /                                                   \n");
		printf("     |     \\|   \\_/   \\_/| |___|         \\__/      \\/                                                 \n");
		printf("                                                                                                           \n");
		printf("     Version 2.4                                                                                           \n");
		printf("     Author:                                                                                               \n");
		printf("            ExecuteIf                                                                                      \n");
		printf("            Hwnd                                                                                           \n");
		printf("            Amiriox                                                                                        \n");
		printf("            Jvav-Top-Programmer                                                                            \n");
		printf("            Caviar-X                                                                                       \n");
		printf("            and so on...                                                                                   \n");
		printf("                                                                                                           \n");
		printf("     Github:https://github.com/JvsvScriptDEV/                                                              \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("                                                                                                           \n");
		printf("----------NodeJv help page(1/1)----------\n");
		printf("console.log(strings): output an strings on th screen\n");
		printf("console.clear():clear the screen\n");
		printf("alert():make an alert windows\n");
		printf("exit():exit with exit value\n");
		printf("----------NodeJv help page(1/1)----------\n\n");
		color(4);
		printf("----------Debug Functions(1/1)-----------\n");
		printf("crash():make JvavScript crash\n");
		printf("----------Debug Functions(1/1)-----------\n");
		color(7);
		
	}
	//console类实现
	else if (!strncmp(arg.c_str(), "console.log(\"", strlen("console.log\"")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else
		{
			for (size_t i = 13; i <= arg.size() - 4; i++)
			{
				putchar(arg[i]);
			}
			putchar('\n');
		}
	}
	else if (!strncmp(arg.c_str(), "console.clear(", strlen("console.clear")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else
		{
#ifdef WIN32
			system("cls");
#endif
#ifdef __linux__
			system("clear");
#endif
//			welcome();
		}
	}
	else if(!strncmp(arg.c_str(), "alert(", strlen("alert(")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else if (arg[arg.size() - 3] != '\"')
			error(2);
		else if (!strncmp(arg.c_str(), "alert(\"\");", arg.size()))
			error(3);
		else
		{
			for (size_t i = 7; i <= arg.size() - 4; i++)
			{
				tmp[i-7]=arg[i];
			}
			MessageBox(NULL,tmp,"NodeJv -- Alert",MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
			memset(tmp,'\0',sizeof(tmp));
		}
	}
	else if(!strncmp(arg.c_str(), "exit(", strlen("exit(")))
	{
		if (arg[arg.size() - 1] != ';')
			error(0);
		else if (arg[arg.size() - 2] != ')')
			error(1);
		else
			for (size_t i = 6; i <= arg.size() - 3; i++) //exit(1);
			{
				tmpint*=10;
				tmpint+=(arg[i]-48);
			}
			exit(tmpint);
	}
	else if(!strncmp(arg.c_str(), "exit", strlen("exit")))
	{
		cout<<"enter \"exit();\" or Press \"Ctrl+C\" to exit.\n";
	}
	else if(!strncmp(arg.c_str(), "crash", strlen("crash")))
	{
		error(int('c'));
	}
	// insert New Functions Here...
	else
	{
		error(111);
	}
}
