#include <iostream>
#include <string>

using namespace std;

class TemperatureSensor {
private:
    int currentTemperature;

public:
    TemperatureSensor() {
        currentTemperature = 0;
    }

    void setCurrentTemperature(int temperature) {
        currentTemperature = temperature;
    }

    int getCurrentTemperature() {
        return currentTemperature;
    }
};

class WaterHeater {
private:
    int heatingTemperature;

public:
    WaterHeater() {
        heatingTemperature = 0;
    }

    void setHeatingTemperature(int temperature) {
        heatingTemperature = temperature;
    }

    int getHeatingTemperature() {
        return heatingTemperature;
    }

    void heatWater(int requiredTemperature) {
        cout << "Heating the water to " << requiredTemperature << " degrees Celsius." << endl;
    }
};

class SmartGeyser {
private:
    TemperatureSensor* sensor;
    WaterHeater* heater;

public:
    SmartGeyser(TemperatureSensor* tempSensor, WaterHeater* waterHeater) {
        sensor = tempSensor;
        heater = waterHeater;
    }

    void activateGeyser() {
        cout << "Geyser activated." << endl;
        int currentTemp = sensor->getCurrentTemperature();
        cout << "Current temperature detected: " << currentTemp << " degrees Celsius." << endl;
        int requiredTemp = calculateRequiredTemperature(currentTemp);
        heater->heatWater(requiredTemp);
    }

    int calculateRequiredTemperature(int currentTemperature) {
        // Adjust temperature based on season (not implemented)
        // For simplicity, assuming a fixed temperature adjustment
        return currentTemperature - 10; // Adjusting for summer by reducing temperature
    }
};

class HomeOwner {
public:
    void getOutOfBed() {
        cout << "Homeowner has gotten out of bed." << endl;
    }
};

int main() {
    TemperatureSensor sensor;
    WaterHeater heater;
    SmartGeyser geyser(&sensor, &heater);
    HomeOwner owner;

    int currentTemp;

    cout << "Enter the current temperature in degrees Celsius: ";
    cin >> currentTemp;

    sensor.setCurrentTemperature(currentTemp);

    owner.getOutOfBed();
    geyser.activateGeyser();

    return 0;
}
