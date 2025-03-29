- 👋 Hi, I’m @R41z0-r0ck
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...

<!---
R41z0-r0ck/R41z0-r0ck is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->


#include <MIDI_TX.h>

MIDI_TX midi;

void setup() {
    midi.begin();
}

void loop() {
    // Send Note On (Middle C, Velocity 100, Channel 1)
    midi.sendNoteOn(60, 100, 1);
    delay(500);

    // Send Note Off (Middle C, Channel 1)
    midi.sendNoteOff(60, 1);
    delay(500);

    // Send Control Change (Modulation Wheel, Value 64, Channel 1)
    midi.sendControlChange(1, 64, 1);
    delay(500);

    // Send Program Change (Patch 5, Channel 1)
    midi.sendProgramChange(5, 1);
    delay(500);

    // Send SysEx Message
    uint8_t sysExMessage[] = {0x7D, 0x01, 0x02, 0x03};  // Custom SysEx
    midi.sendSysEx(sysExMessage, sizeof(sysExMessage));
    delay(1000);
}
