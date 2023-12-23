#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char plane_type[32];
    char flight_date[32];
    char from_city[32];
    char to_city[32];
    char time[8];
} AIRPORT;


AIRPORT CreateAirport();
void PrintAirport(AIRPORT *summer_planes);


int main () {

    int n;
    printf("n: ");
    scanf("%d", &n);

    AIRPORT *stations = malloc(n * sizeof(AIRPORT));

    for(int i=0; i<n; i++) {
        stations[i] = CreateAirport();
    }

    for(int i=0; i<n; i++) {
        if((stations[i].time[1] == '2' || stations[i].time[1] == '3') && strcmp(stations[i].to_city, "TASHKENT") == 0)
            PrintAirport(stations+i);
    }

    free(stations);

    return 0;
}



AIRPORT CreateAirport() {
    AIRPORT plane;
    int check = 1, len;
    puts("");

    fgetc(stdin);
    printf("plane type: ");
    scanf("%[^\n]s", plane.plane_type);

    do {
        fgetc(stdin);
        if (check)
            check--;
        else
            printf("Please enter flightdate as requested :)\n");

        printf("flight date (01.01.2001): ");
        scanf("%[^\n]s", plane.flight_date);
    } while (!(strlen(plane.flight_date) == 10 && plane.flight_date[2] == '.' && plane.flight_date[5] == '.'));

    fgetc(stdin);
    printf("from city: ");
    scanf("%[^\n]s", plane.from_city);

    len = strlen(plane.from_city);
    for(int i=0; i<len; i++)
        plane.from_city[i] = toupper(plane.from_city[i]);

    fgetc(stdin);
    printf("to city: ");
    scanf("%[^\n]s", plane.to_city);

    len = strlen(plane.to_city);
    for(int i=0; i<len; i++)
        plane.to_city[i] = toupper(plane.to_city[i]);

    check = 1;
    do {
        fgetc(stdin);
        if (check)
            check--;
        else
            printf("Please enter flightdate as requested :)\n");

        printf("time (from 00:00 to 23:59): ");
        scanf("%[^\n]s", plane.time);
    } while(!(strlen(plane.time) == 5 && plane.time[2] == ':'));

    return plane;
}


void PrintAirport(AIRPORT *summer_planes) {
    puts("");

    printf("%s\n", summer_planes->plane_type);
    printf("%s\n", summer_planes->flight_date);
    printf("%s\n", summer_planes->from_city);
    printf("%s\n", summer_planes->to_city);
    printf("%s\n", summer_planes->time);
}
