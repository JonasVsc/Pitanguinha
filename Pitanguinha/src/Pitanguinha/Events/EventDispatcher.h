#pragma once

#include "Event.h"

class EventDispatcher
{
	template<typename T>
	using EventFn = std::function<bool(T&)>;

public:
	EventDispatcher(Event &event) : m_Event(event) {}

	template<typename T>
	bool Dispatch(EventFn<T> func) 
	{
		if (m_Event.GetEventType() == T::GetStaticType()) 
		{
			m_Event.handled = func(*(T*)&m_Event);
			return true;
		}
		return false;
	}

private:

	Event& m_Event;
};