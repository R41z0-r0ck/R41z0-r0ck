#ifndef MIDI_TX_H
#define MIDI_TX_H

#include <Arduino.h>

class MIDI_TX {
public:
    MIDI_TX(HardwareSerial &serialPort = Serial1, uint32_t baudRate = 31250);
    
    void begin();
    void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel);
    void sendNoteOff(uint8_t note, uint8_t channel);
    void sendControlChange(uint8_t control, uint8_t value, uint8_t channel);
    void sendProgramChange(uint8_t program, uint8_t channel);
    void sendSysEx(const uint8_t *data, uint8_t length);

private:
    HardwareSerial &midiSerial;
    uint32_t baudRate;
};

#endif