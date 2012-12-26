#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void writeHeader(FILE *p);
void writeFloatToFile(FILE *fp, int nth, float val);
float readFloatFromFile(FILE *fp, int nth);

int main(void) {
	FILE *fp = fopen("db.advs", "w+");
	writeHeader(fp);
	writeFloatToFile(fp, 0, 1);
	int i;
	for(i = 0; i < 1000000; i++) {
		writeFloatToFile(fp, i, 3.4028234e38);
	}
	fclose(fp);
	
	fp = fopen("db.advs", "rb");

	for(i = 0; i < 100; i++) {
		printf("[%d] => %f\n", i,readFloatFromFile(fp, i));
	}
	fclose(fp);

	return EXIT_SUCCESS;
}

void writeHeader(FILE *fp) {
	char *header = "ADVS";
	fprintf(fp, "%s", header);
}

void writeFloatToFile(FILE *fp, int nth, float val) {
	char buffer[4] = {0};
	fseek(fp, nth*4, 4);
	memcpy(buffer, &val, 4);
	fwrite(buffer, 4, 1, fp);
}

float readFloatFromFile(FILE *fp, int nth) {
	char buffer[4] = {0};
	fseek(fp, 4*nth+8, SEEK_SET);
	fread(buffer, 4, 1, fp);

	float inFile = 0;
	memcpy(&inFile, buffer, 4);
	return inFile;
}
