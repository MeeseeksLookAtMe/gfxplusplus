// Copyright 2020 Robert Carneiro, Derek Meer, Matthew Tabak, Eric Lujan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef _HANDSHAKE_CLIENT
#define _HANDSHAKE_CLIENT

#include "../Backend/Database/GList.h"
#include "../Backend/Networking/instance.h"
#include "../Backend/Networking/service.h"

class Handshake_Client : public GNet::Service
{
public:
	shmea::GList execute(class GNet::Instance* cInstance, const shmea::GList& data)
	{
		// Log the server into the client
		shmea::GList retList;
		if (data.size() < 2)
			return retList;

		// Check the characters in the name
		std::string clientName = data.getString(0);
		if (!GNet::Instance::validName(clientName))
			clientName = "";
		cInstance->setName(clientName);

		// get the new encryption key
		int64_t newKey = data.getLong(1);

		// Set the new instance key
		cInstance->setKey(newKey);

		return retList;
	}

	GNet::Service* MakeService() const
	{
		return new Handshake_Client();
	}

	std::string getName() const
	{
		return "Handshake_Client";
	}
};

#endif
