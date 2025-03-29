#include "MIDI_TX.h"

MIDI_TX::MIDI_TX(HardwareSerial &serialPort, uint32_t baudRate)
    : midiSerial(serialPort), baudRate(baudRate) {}

void MIDI_TX::begin() {
    midiSerial.begin(baudRate);
}

void MIDI_TX::sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) {
    midiSerial.write(0x90 | (channel & 0x0F));
    midiSerial.write(note & 0x7F);
    midiSerial.write(velocity & 0x7F);
}

void MIDI_TX::sendNoteOff(uint8_t note, uint8_t channel) {
    midiSerial.write(0x80 | (channel & 0x0F));
    midiSerial.write(note & 0x7F);
    midiSerial.write(0x00);
}

void MIDI_TX::sendControlChange(uint8_t control, uint8_t value, uint8_t channel) {
    midiSerial.write(0xB0 | (channel & 0x0F));
    midiSerial.write(control & 0x7F);
    midiSerial.write(value & 0x7F);
}

void MIDI_TX::sendProgramChange(uint8_t program, uint8_t channel) {
    midiSerial.write(0xC0 | (channel & 0x0F));
    midiSerial.write(program & 0x7F);
}

void MIDI_TX::sendSysEx(const uint8_t *data, uint8_t length) {
    midiSerial.write(0xF0);  // SysEx start
    for (uint8_t i = 0; i < length; i++) {
        midiSerial.write(data[i] & 0x7F);
    }
    midiSerial.write(0xF7);  // SysEx end
}