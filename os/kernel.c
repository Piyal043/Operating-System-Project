#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
int kmain()
{
  
	   clearScreen();
       print("Welcome to Piyal's operating system\nPlease enter a command\n");
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
			
			print("\n Give input: \n");
			
			string nw=readStr();
			print("\n output: \n");
			print(nw);
			
		}
		else if(strEql(ch,"match"))
			{
				print("Enter string: ");
				ch = readStr();
				match(ch);
			}
                else
                {
                        print("\nBad command!\n");
                }
                
                print("\n");        
       }
}
