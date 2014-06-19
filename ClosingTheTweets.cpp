#include<iostream>/**For the basic input output functions .*/
#include<cstdlib>/**For the atoi function .*/

using namespace std ;

int n ;/**Making it global would help me to use it in the main function as well as other functions without passing .*/
bool Tweet[1000] ;/** Again the same reason for making it global .*/

int CountOpen()/**This function calulates the number of open tweets currently on the screen .*/
{
	int count = 0 ;
	for(int i = 0 ; i < n ; i ++ )
	{
		if(Tweet[i])
		{
			count++ ;	
		}
	}
	return count ;
}
void CloseAll()/**Now this function closes all of the tweets on the current page .*/
{
	for(int i = 0 ; i < n ; i ++)
	{
		Tweet[i] = false ;
	}
}

void Toggle(int i)/**This function is equivalent to the click on the screen .*/
{
	if(Tweet[i-1])
	{
		Tweet[i-1] = false ;
	}
	else
	{
		Tweet[i-1] = true ;
	}
}
int main()
{
	int k ;/**This variable stores the number of operations done on the array .*/
	string s ;
	scanf("%d",&n) ;
	scanf("%d",&k) ;
	for(int i = 0 ; i < n  ; i++)
	{
		Tweet[i] = false ;/**Here false state implies closed .*/
	}
	for(int i = 0 ; i < k ; i++ )
	{
		cin >> s ;
		if(s == "CLOSEALL")
		{
			CloseAll() ;
			printf("%d \n" ,CountOpen() ) ;
		}
		else
		{
			cin >> s ;
			Toggle(atoi(s.c_str())) ;
			printf("%d \n" ,CountOpen() ) ;
		}
	}
}
