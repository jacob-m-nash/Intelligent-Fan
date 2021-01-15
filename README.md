# Intelligent-Fan

This project is to create an intelligent temperature controlled personal fan using an Arduino Uno and a 140mm computer fan. The fan will have two operating modes: Standard mode is just simply where the user turns on and off the fan with the switch. Intelligent mode where the fan automatically turns on and off depending on the ambient temperature, while in intelligent mode the fan can still be switched on and off by the user.

## What makes this fan intelligent?

Using the Arduino,  this fan will be controlled by the ambient air temperate as well as a user operated switch. The fan will learn the user preference of what temperature the user turns the fan on and off. The arduino learns using a modified chess Elo rating system where instead of a numerical rating and player vs player outcome the algorithm  uses temperature values and predicted vs actual temperatures.

### Pseudo Code

``` Pseudo Code
if fan is turned on by user then
    if turn on predicted temperature is higher that current temperature then
        turn on predicted temperature 'loses'
        temperature for turn on predicted value (elo) is recalculated 
    end if 

    if turn on predicted temperature is lower that current temperature then
        turn on predicted temperature 'wins'
        temperature for predicted value (elo) is recalculated 
    end if

end if

if fan is turned off by user then
    if turn off predicted temperature is higher that current temperature then
        turn off predicted temperature 'wins'
        temperature for turn off predicted value (elo) is recalculated 
    end if

    if turn off predicted temperature is lower that current temperature then
        turn off predicted temperature 'loses'
        temperature for turn off predicted value (elo) is recalculated 
    end if

end if
```

## Parts list

* Arduino Uno

* 140mm computer fan

* LM35 temperature sensor

* BC108 transistor

* MT3608 DC-DC step up converter

## Circuit diagram

![Circuit diagram](assets/circuit.png)
