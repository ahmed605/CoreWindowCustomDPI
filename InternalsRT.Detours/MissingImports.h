#pragma once

#include <Windows.h>

extern "C"
{
    // MemoryApi.h

    WINBASEAPI
        SIZE_T
        WINAPI
        VirtualQueryEx(
            _In_ HANDLE hProcess,
            _In_opt_ LPCVOID lpAddress,
            _Out_writes_bytes_to_(dwLength, return) PMEMORY_BASIC_INFORMATION lpBuffer,
            _In_ SIZE_T dwLength
        );

    WINBASEAPI
        _Success_(return != FALSE)
        BOOL
        WINAPI
        ReadProcessMemory(
            _In_ HANDLE hProcess,
            _In_ LPCVOID lpBaseAddress,
            _Out_writes_bytes_to_(nSize, *lpNumberOfBytesRead) LPVOID lpBuffer,
            _In_ SIZE_T nSize,
            _Out_opt_ SIZE_T * lpNumberOfBytesRead
        );

    WINBASEAPI
        _Success_(return != FALSE)
        BOOL
        WINAPI
        WriteProcessMemory(
            _In_ HANDLE hProcess,
            _In_ LPVOID lpBaseAddress,
            _In_reads_bytes_(nSize) LPCVOID lpBuffer,
            _In_ SIZE_T nSize,
            _Out_opt_ SIZE_T * lpNumberOfBytesWritten
        );

    WINBASEAPI
        _Ret_maybenull_  __out_data_source(FILE)
        LPVOID
        WINAPI
        MapViewOfFileEx(
            _In_ HANDLE hFileMappingObject,
            _In_ DWORD dwDesiredAccess,
            _In_ DWORD dwFileOffsetHigh,
            _In_ DWORD dwFileOffsetLow,
            _In_ SIZE_T dwNumberOfBytesToMap,
            _In_opt_ LPVOID lpBaseAddress
        );

    // ProccessThreadApi.h

    WINBASEAPI
        BOOL
        WINAPI
        SetThreadContext(
            _In_ HANDLE hThread,
            _In_ CONST CONTEXT* lpContext
        );

    // FileApi.h

    WINBASEAPI
        DWORD
        WINAPI
        GetFileSize(
            _In_ HANDLE hFile,
            _Out_opt_ LPDWORD lpFileSizeHigh
        );
}