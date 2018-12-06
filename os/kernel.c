#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
int kmain()
{
  
	   clearScreen();
       print("Welcome to Piyal's operating system\nPlease enter username and password\n");
	string username = "os";
	   string password = "1111";
	   
	   string inp = 0;
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Login Done!\n");
			   break;
		   }
		   print("Wrong info. Try again\n");
	   }
	print("Enter your command\n");
       while (1)
       {
                print("\nPiyal:> ");
                
                string ch = readStr();
                if(strEql(ch,"cmd"))
                {
                        print("\nYou are allready in cmd\n");
                }
                else if(strEql(ch,"clean"))
                {
                        clearScreen();
                }
                else if(strEql(ch,"print"))
		{
			
			print("Give input: \n");
			
			string nw=readStr();
			print("output: \n");
			print(nw);
			
		}
		else if(strEql(ch,"match"))
			{
				print("Enter string: ");
				ch = readStr();
				match(ch);
			}
		else if(strEql(ch,"off"))
		{
			print("Logging off\n");
			break;
		}
                else
                {
                        print("\nBad command!\n");
                }
                
                print("\n");    
		//newLineCheck( ) ;  
       }
}
