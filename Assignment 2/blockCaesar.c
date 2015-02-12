#include <stdio.h>

char sentence[100];

cipherImproved(int keys[], char sentence[]){
	
	int i=0;
	int j=0;

	//Cipher each character separately
	for(i=0; i<100; i++){
		int cipherIncrement = keys[j]; //store the current increment that will be used in this iteration
		cipherIncrement = cipherIncrement % 26; //convert it to an alphabet increment in case key[j] > 26
		
		//If we reach the null character, then stop ciphering
		if (sentence[i] == '\0') break;
		
		//If this character is a space, then we skip it
		if (sentence[i] == ' ') {
			j = (j+1) % 3 ; // continue to loop through the key array
			continue;
		}
		
		//CASE 1: Character is lower-case
		if (sentence[i] >= 'a' && sentence[i] <= 'z'){
			//cipher increment pushes character below lower bound:
			if (sentence[i] + cipherIncrement < 'a'){
				sentence[i] = sentence[i] + cipherIncrement + 26;
				j = (j+1) % 3;
				continue;
			}
			//cipher increment pushes character above upper bound:
			if (sentence[i] + cipherIncrement > 'z'){
				sentence[i] = sentence[i] + cipherIncrement - 26;
				j = (j+1) % 3;
				continue;
			}
		}
		//cipher increment is perfect! cipher it up!
		else{
			sentence[i] = sentence[i] + cipherIncrement;
			j = (j+1) % 3;
			continue;
		}
		
		//CASE 2: Character is upper-case
		if (sentence[i] >= 'A' && sentence[i] <= 'Z'){
			//cipher increment pushes character below lower bound:
			if (sentence[i] + cipherIncrement < 'A'){
				sentence[i] = sentence[i] + cipherIncrement + 26;
				j = (j+1) % 3;
				continue;
			}
			//cipher increment pushes character above upper bound:
			if (sentence[i] + cipherIncrement > 'Z'){
				sentence[i] = sentence[i] + cipherIncrement - 26;
				j = (j+1) % 3;
				continue;
			}
		}
		else{
			sentence[i] = sentence[i] + cipherIncrement;
			j = (j+1) % 3;
			continue;
		}

		//At this point, either the loop has continued or a non-alphabet character has been inputted. Skip it.
		j = (j+1) % 3;
	}
}

int main(void){
	int keys[3];
	int i;

	//prompt user for what kind of ciphering they want!
	printf("%s", "Sentence: " );
	fgets(sentence, 100, stdin);
	
	printf("%s", "Keys: ");
	scanf("%d %d %d", &keys[0], &keys[1], &keys[2]);

	//call the cipher function and transform sentence array
	cipherImproved(keys, sentence);
	
	//Print the result
	printf("%s", "Cipher");
	for (i=0; i<100; i++){
		printf("%c", sentence[i]);
	}
	printf("\n%s\n", "Done");
}
