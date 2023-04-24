#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

// BYTE EVENTS
uint8_t FLP_Byte = 0;
uint8_t FLP_Enabled = 0;
uint8_t FLP_NoteOn = 1; //+pos (byte)
uint8_t FLP_Vol = 2;
uint8_t FLP_Pan = 3;
uint8_t FLP_MIDIChan = 4;
uint8_t FLP_MIDINote = 5;
uint8_t FLP_MIDIPatch = 6;
uint8_t FLP_MIDIBank = 7;
uint8_t FLP_LoopActive = 9;
uint8_t FLP_ShowInfo = 10;
uint8_t FLP_Shuffle = 11;
uint8_t FLP_MainVol = 12;
uint8_t FLP_Stretch = 13; // old byte version
uint8_t FLP_Pitchable = 14;
uint8_t FLP_Zipped = 15;
uint8_t FLP_Delay_Flags = 16;
uint8_t FLP_PatLength = 17;
uint8_t FLP_BlockLength = 18;
uint8_t FLP_UseLoopPoints = 19;
uint8_t FLP_LoopType = 20;
uint8_t FLP_ChanType = 21;
uint8_t FLP_MixSliceNum = 22;
uint8_t FLP_EffectChannelMuted = 27;

// WORD EVENTS
uint8_t FLP_Word = 64;
uint8_t FLP_NewChan = FLP_Word;
uint8_t FLP_NewPat = FLP_Word + 1; //+PatNum (word)
uint8_t FLP_Tempo = FLP_Word + 2;
uint8_t FLP_CurrentPatNum = FLP_Word + 3;
uint8_t FLP_PatData = FLP_Word + 4;
uint8_t FLP_FX = FLP_Word + 5;
uint8_t FLP_Fade_Stereo = FLP_Word + 6;
uint8_t FLP_CutOff = FLP_Word + 7;
uint8_t FLP_DotVol = FLP_Word + 8;
uint8_t FLP_DotPan = FLP_Word + 9;
uint8_t FLP_PreAmp = FLP_Word + 10;
uint8_t FLP_Decay = FLP_Word + 11;
uint8_t FLP_Attack = FLP_Word + 12;
uint8_t FLP_DotNote = FLP_Word + 13;
uint8_t FLP_DotPitch = FLP_Word + 14;
uint8_t FLP_DotMix = FLP_Word + 15;
uint8_t FLP_MainPitch = FLP_Word + 16;
uint8_t FLP_RandChan = FLP_Word + 17;
uint8_t FLP_MixChan = FLP_Word + 18;
uint8_t FLP_Resonance = FLP_Word + 19;
uint8_t FLP_LoopBar = FLP_Word + 20;
uint8_t FLP_StDel = FLP_Word + 21;
uint8_t FLP_FX3 = FLP_Word + 22;
uint8_t FLP_DotReso = FLP_Word + 23;
uint8_t FLP_DotCutOff = FLP_Word + 24;
uint8_t FLP_ShiftDelay = FLP_Word + 25;
uint8_t FLP_LoopEndBar = FLP_Word + 26;
uint8_t FLP_Dot = FLP_Word + 27;
uint8_t FLP_DotShift = FLP_Word + 28;
uint8_t FLP_LayerChans = FLP_Word + 30;

// DWORD EVENTS
uint8_t FLP_Int = 128;
uint8_t FLP_Color = FLP_Int;
uint8_t FLP_PlayListItem = FLP_Int + 1; //+Pos (word) +PatNum (word)
uint8_t FLP_Echo = FLP_Int + 2;
uint8_t FLP_FXSine = FLP_Int + 3;
uint8_t FLP_CutCutBy = FLP_Int + 4;
uint8_t FLP_WindowH = FLP_Int + 5;
uint8_t FLP_MiddleNote = FLP_Int + 7;
uint8_t FLP_Reserved = FLP_Int + 8; // may contain an invalid version info
uint8_t FLP_MainResoCutOff = FLP_Int + 9;
uint8_t FLP_DelayReso = FLP_Int + 10;
uint8_t FLP_Reverb = FLP_Int + 11;
uint8_t FLP_IntStretch = FLP_Int + 12;
uint8_t FLP_SSNote = FLP_Int + 13;
uint8_t FLP_FineTune = FLP_Int + 14;
uint8_t FLP_FineTempo = 156;

// TEXT EVENTS
uint8_t FLP_Undef = 192; //+Size (char length)
uint8_t FLP_Text = FLP_Undef; //+Size (char length)+Text  (Null Term. String)
uint8_t FLP_Text_ChanName = FLP_Text; // name for the current channel
uint8_t FLP_Text_PatName = FLP_Text + 1; // name for the current pattern
uint8_t FLP_Text_Title = FLP_Text + 2; // title of the loop
uint8_t FLP_Text_Comment = FLP_Text + 3; // old comments in text format.
 // Not used anymore
uint8_t FLP_Text_SampleFileName = FLP_Text + 4; // filename for the sample in the current channel, stored as relative path
uint8_t FLP_Text_URL = FLP_Text + 5;
uint8_t FLP_Text_CommentRTF = FLP_Text + 6; // new comments in Rich Text format
uint8_t FLP_Text_Version = FLP_Text + 7;
uint8_t FLP_Text_PluginName = FLP_Text + 9; // plugin file name (without path)

uint8_t FLP_Text_EffectChanName = FLP_Text + 12;
uint8_t FLP_Text_MIDICtrls = FLP_Text + 16;
uint8_t FLP_Text_Delay = FLP_Text + 17;
uint8_t FLP_Text_TS404Params = FLP_Text + 18;
uint8_t FLP_Text_DelayLine = FLP_Text + 19;
uint8_t FLP_Text_NewPlugin = FLP_Text + 20;
uint8_t FLP_Text_PluginParams = FLP_Text + 21;
uint8_t FLP_Text_ChanParams = FLP_Text + 23;// block of various channel params (can grow)
uint8_t FLP_Text_EnvLfoParams = FLP_Text + 26;
uint8_t FLP_Text_BasicChanParams= FLP_Text + 27;
uint8_t FLP_Text_OldFilterParams= FLP_Text + 28;
uint8_t FLP_Text_AutomationData = FLP_Text + 31;
uint8_t FLP_Text_PatternNotes = FLP_Text + 32;
uint8_t FLP_Text_ChanGroupName = FLP_Text + 39;
uint8_t FLP_Text_PlayListItems = FLP_Text + 41;

const vector<char> valid_header = {'F', 'L', 'h', 'd'};

// Read bytes into a vector
vector<char> read_bytes(char const* filename)
{
	ifstream in(filename, ios::binary|ios::ate);

	ifstream::pos_type pos = in.tellg();

	std::vector<char> result(pos);

	in.seekg(0, ios::beg);
	in.read(&result[0], pos);
	return result;
}

// Parse each char
void parse_char(byte c)
{
	printf("%c\n", (char)c);
}

bool parse_header(vector<char>* bytes)
{
	vector<char> header = vector<char>(bytes->begin(), bytes->begin() + 4);
	if (header != valid_header) {
		cout << "Invalid input file" << endl;
		return false;
	}

	// Erase FLdh header section and FLdt (we're done wid it)
	bytes->erase(bytes->begin(), bytes->begin() + 14);

	return true;
}

// the length of the data within flp
// First 4 bytes: FLdt (Fruity Loops data)
// Second 4 bytes: Length of the data chunk
unsigned long get_chunk_len(vector<char>* bytes) 
{
	unsigned int value;
	byte len_chunk_raw[4];

	// erase FLdt
	bytes->erase(bytes->begin(), bytes->begin() + 4);

	// Copy raw bytes
	for (int i = 0; i < 4; i++) {
		len_chunk_raw[i] = (byte) (*bytes)[i];
	}

	// copy bytes into uint
	memcpy(&value, len_chunk_raw, sizeof(value));

	// erase what we just read into value
	bytes->erase(bytes->begin(), bytes->begin() + 4);

	return value;
}

// void extract(uint8_t eventId, *byte data)
// {
// 	printf("EventId: %i | data: %d", eventId, data);
// }

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "Please provide a file path" << endl;
		return 1;
	}

	vector<char> bytes = read_bytes(argv[1]);

	bool valid = parse_header(&bytes);
	if (!valid) return 1;

	// We need to look at the next 8 bytes
	// then we know the length of the data chunk
	unsigned int len = get_chunk_len(&bytes);
	printf("Size of data chunk: %d\n", len);

	// for (int i = 0; i < bytes.size(); i++)
	for (int i = 0; i < 1000; i++)
	{
		// Retrieve event id - this tells us the size of the data to come
		uint8_t eventId = (uint8_t) bytes[i++];

		// BYTE or uint8_t
		if (eventId < 64)
		{
			byte data = (byte) bytes[i];
			// extract info from the data and event
			printf("BYTE %i\n", eventId);

			// adjust the iterator
			i += 1;
			continue;
		}
		// WORD or uint16_t
		else if (eventId < 128)
		{
			byte data[2];
			data[0] = (byte) bytes[i];
			data[1] = (byte) bytes[i + 1];

			printf("WORD %i\n", eventId);
			// adjust iterator
			i += 2;
			continue;
		}
		// DWORD or uint32_t
		else if (eventId < 193)
		{
			byte data[4];
			data[0] = (byte) bytes[i];
			data[1] = (byte) bytes[i + 1];
			data[2] = (byte) bytes[i + 2];
			data[3] = (byte) bytes[i + 3];

			printf("DWORD %i\n", eventId);

			// adjust iterator ( eventId = 1, DWORD = 4 )
			i += 4;
			continue;
		}
		// Variable length
		else {
			printf("TEXT\n");

			uint32_t var_len = 0;
		    int shift = 0;
		    uint8_t cur_byte;
		    do {
		        cur_byte = bytes[i++];
		        var_len |= (cur_byte & 0x7F) << shift;
		        shift += 7;
		    } while (cur_byte & 0x80);
		    printf("Size of text chunk: %d\n", var_len);
			// add first 7 bits to size
			// if bit 8 is off, continue processing data
			// else the next 7 bits should be also added to size... and so on

			i += var_len;
			continue;
		}
	}

	return 0;
}
