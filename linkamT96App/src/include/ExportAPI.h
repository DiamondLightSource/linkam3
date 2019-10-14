/************************************************************************
*
*   File:           ExportAPI.h
*
*   Description:    This header defines the export/import symbols for
*                   the Linkam SDK library.
*
*   Copyright © 2018-2019 Linkam Scientific Instruments. All rights reserved
************************************************************************/
#ifndef LINKAM_SDK__EXPORT_API
#define LINKAM_SDK__EXPORT_API

#if defined(_WIN32) || defined(_WIN64)
    #ifdef __cplusplus
        #define LINKAM_API_EXPORT       extern "C" __declspec(dllexport)
        #define LINKAM_API_IMPORT       extern "C" __declspec(dllimport)
    #else
        #define LINKAM_API_EXPORT       __declspec(dllexport)
        #define LINKAM_API_IMPORT       __declspec(dllimport)        
    #endif
#else
    #ifdef __cplusplus
        #define LINKAM_API_EXPORT       extern "C" __attribute__ ((visibility("default")))
        #define LINKAM_API_IMPORT       extern "C"
    #else
        #define LINKAM_API_EXPORT       __attribute__ ((visibility("default")))
        #define LINKAM_API_IMPORT               
    #endif
#endif


#ifdef LINKAM_EXPORT_SYMBOLS
    #define LINKAM_API_CALL         LINKAM_API_EXPORT
#else
    #define LINKAM_API_CALL         LINKAM_API_IMPORT    
#endif

#endif // LINKAM_SDK__EXPORT_API


