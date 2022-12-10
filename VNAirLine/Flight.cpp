#include "Flight.h"

int Flight::nextFlightDay = 0;
vector<Flight> Flight::flightList = {};


//Getters & Setters
int Flight::getNoOfSeats() {
    return numOfSeatsInTheFlight;
}
string Flight::getFlightNumber() {
    return flightNumber;
}
void Flight::setNoOfSeatsInTheFlight(int numOfSeatsInTheFlight) {
    this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
}
string Flight::getFlightTime() {
    return flightTime;
}
vector<Flight> Flight::getFlightList() {
    return flightList;
}
vector<Customer> Flight::getListOfRegisteredCustomersInAFlight() {
    return listOfRegisteredCustomersInAFlight;
}
string Flight::getFlightSchedule() {
    return flightSchedule;
}
string Flight::getFromWhichCity() {
    return fromWhichCity;
}
string Flight::getGate() {
    return gate;
}
string Flight::getToWhichCity() {
    return toWhichCity;
}

//Constructors
Flight::Flight()
{
    this->flightSchedule = nullptr;
    this->flightNumber = nullptr;
    this->numOfSeatsInTheFlight = 0;
    toWhichCity = nullptr;
    fromWhichCity = nullptr;
    this->gate = nullptr;
}
Flight::Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string** chosenDestinations, string* distanceBetweenTheCities, string gate)
{
    this->flightSchedule = flightSchedule;
    this->flightNumber = flightNumber;
    this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
    this->fromWhichCity = chosenDestinations[0][0];
    this->toWhichCity = chosenDestinations[1][0];
    this->distanceInMiles = stod(distanceBetweenTheCities[0]);
    this->distanceInKm = stod(distanceBetweenTheCities[1]);
    this->flightTime = calculateFlightTime(distanceInMiles);
    this->listOfRegisteredCustomersInAFlight = {};
    this->gate = gate;
}

//Method
void Flight::flightScheduler()
{
    int numOfFlights = 15;
    RandomGenerator random;
    string** chosenDestinations;
    string* distanceBetweenTheCities;
    for (int i = 0; i < numOfFlights; i++)
    {
        chosenDestinations = random.randomDestinations();
        distanceBetweenTheCities = calculateDistance(stod(chosenDestinations[0][1]), stod(chosenDestinations[0][2]), stod(chosenDestinations[1][1]), stod(chosenDestinations[1][2]));
        string flightSchedule = createNewFlightsAndTime();
        string flightNumber = random.randomFlightNumGen(2, 1);
        int numOfSeatsInTheFlight = random.randomOfNumSeat();
        string gate = random.randomFlightNumGen(1, 30);
        flightList.push_back(Flight(flightSchedule, flightNumber, numOfSeatsInTheFlight, chosenDestinations, distanceBetweenTheCities, gate));
    }
}

string Flight::tostring(int)
{
    return;
}
