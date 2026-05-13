#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) 
{
	int char_index[128];
	for(int i=0;i<128;i++)
	{
		char_index[i]=-1;
	}
	int left=0;
	int max_length=0;
	int len=strlen(s);
	int right=0;
	for(right=0;right<len;right++)
	{
		unsigned char current_char=s[right];
		if(char_index[current_char]>=left)
		{
			left=char_index[current_char]+1;
		}
		char_index[current_char]=right;
		int current_length=right-left+1;
		if(current_char>max_length)
		{
			max_length = current_length;
		}
	}
	return max_length;
}
int main() {
    char s[1000]; 
    printf("qinshuruyigezifuchuan: ");
	scanf("%s",&s);
    int result = lengthOfLongestSubstring(s);
    printf("The length of longest substring is: %d\n", result);
    return 0;
}