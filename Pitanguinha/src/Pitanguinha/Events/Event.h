#pragma once


enum class EventType
{
	None = 0,
	WindowClose,
};


class Event
{
public:
	
	virtual EventType GetEventType() const = 0;

	// static EventType GetStaticType() { return EventType::##type;  } // Implement inside event specific type classes

	bool handled = false;
};