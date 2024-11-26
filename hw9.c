#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int convcase(int ch) {
	const int diff = 'a' - 'A';
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch + diff;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		return ch - diff;
	}
	else
	{
		return ch;
	}
}

int main(void) {
	char str[40];
	int i;
	printf("INPUT > \n");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	for (i = 0; i < strlen(str); i++)
	{
		str[i] = convcase(str[i]);
	}

	printf("OUTPUT > %s", str);
	return 0;
}