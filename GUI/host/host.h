#pragma once

#include "common.h"
#include "textthread.h"

namespace Host
{
	using ProcessEventHandler = std::function<void(DWORD)>;
	using ThreadEventHandler = std::function<void(TextThread&)>;
	using HookEventHandler = std::function<void(HookParam, DWORD processId, const std::wstring& text)>;
	void Start(ProcessEventHandler Connect, ProcessEventHandler Disconnect, ThreadEventHandler Create, ThreadEventHandler Destroy, TextThread::OutputCallback Output);

	void InjectProcess(DWORD processId);
	void DetachProcess(DWORD processId);
	void InsertHook(DWORD processId, HookParam hp);
	void FindHooks(DWORD processId, SearchParam sp, HookEventHandler HookFound = {});

	HookParam GetHookParam(ThreadParam tp);

	TextThread& GetThread(ThreadParam tp);
	void AddConsoleOutput(std::wstring text);

	inline int defaultCodepage = SHIFT_JIS;

	constexpr ThreadParam console{ 0, -1LL, -1LL, -1LL }, clipboard{ 0, 0, -1LL, -1LL };
}
