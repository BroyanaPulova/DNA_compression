#include "SpectreElement.h"


void SpectreElement::AddValue(unsigned val)
{
	Value ^= val;
}

void SpectreElement::Calculate()
{
	count = doBinaryJunk(Value, &ValueStr);
}

int SpectreElement::GetCountOneBits()
{
	if (count != -1)
		return count;

	count = doBinaryJunk(Value, &ValueStr);
	return count;
}

string SpectreElement::ToString(int sizeWord)
{
	bitset<32> set(Value);
	return set.to_string();
}

string SpectreElement::GetBinaryValue(int sizeWord)
{
	bitset<32> set(Value);
	string binaryNumber = set.to_string();

	string result = binaryNumber.erase(0, 32 - sizeWord);

	return result;
}

int SpectreElement::doBinaryJunk(unsigned n, string * value)
{
	unsigned mask = 1 << (std::numeric_limits<unsigned>::digits - 1);

	unsigned count[2] = { 0 };

	// skip leading 0's:
	while (mask && !(mask & n))
		mask >>= 1;

	while (mask)
	{
		unsigned digit = (mask & n) != 0;
		++count[digit];

		(*value) += (mask & n) != 0 ? "1" : "0";

		mask >>= 1;
	}

	return count[1];
}
