// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file SensorCombinedPublisher.h
 * This header file contains the declaration of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _SENSORCOMBINED_PUBLISHER_H_
#define _SENSORCOMBINED_PUBLISHER_H_

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>

#include "SensorCombinedPubSubTypes.h"

using namespace eprosima::fastrtps;

class SensorCombinedPublisher 
{
public:
	SensorCombinedPublisher();
	virtual ~SensorCombinedPublisher();
	bool init(std::string &uart);
	void run();
private:
	Participant *mp_participant;
	Publisher *mp_publisher;
	int m_uart_filestream;
	std::string m_uart;
	
	class PubListener : public PublisherListener
	{
	public:
		PubListener() : n_matched(0){};
		~PubListener(){};
		void onPublicationMatched(Publisher* pub,MatchingInfo& info);
		int n_matched;
	} m_listener;
	SensorCombinedPubSubType myType;

	uint8_t init_uart();
	uint8_t readFromUART(SensorCombined &st);
};

#endif // _SENSORCOMBINED_PUBLISHER_H_
