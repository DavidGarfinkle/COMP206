#include <stdio.h>

/******************************************* A NOTE TO MY MARKER ********************************************************
THINGS THAT ARE WRONG IN THIS: 
* -> the result is often larger than what an int can hold. It said in the assignment to return an int value hashNumber, so it is often negative. that is, hashNumber != (sum of chars)^key because it will become some negative number. However, this can be remedied by
* -> when you input more than 100 characters, the program no longer asks for a key and it instead inputs a random but consistent 9-digit integer. I have no idea why and I've spent over 2 hours trying to figure it out, so I have given up. I am sorry to have failed you. :(
*/

char sentence[100];

int hash(int key) {
	int i; //index for loops
	int sum=0;
	
	//Sum up the characters in the sentence array
	for(i=0; i<100; i++){
		sum += sentence[i];
	}

	//Put the sum to the power of key
	int result=sum;
	for (i=1; i<key; i++){
		result = result*sum;
	}
	
	//Return result, which should be: (sum of chars)^key
	return result;
}

int main(void) {
	int i; //index variable
	char c; //to read STDIN

	//Get input sentence using getchar() - do not count 'enter' key and do not exceed 100 characters
	printf("Please enter a sentence. Keep it less than 100 characters:");
	i=0; 
	while ((c = getchar()) != '\n' && i<100) sentence[i++] = c;

	//Get input key
	fflush(stdin); //clear input buffer
	fflush(stdout);
	printf("Please enter a key:");
	int key;
	scanf("%d", &key);
	
	//Call hash on input key and store result
	int hashNumber = hash(key);

	//Print result
	printf("%d\nDone.", hashNumber); //Result + carriage return + 'Done.'
}

