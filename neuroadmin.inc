/*
* neuroadmin-samp-wrapper
* Wrapper to use the NeuroAdmin API from Pawn (SAMP)
* GitHub: https://github.com/NeuroTracing/neuroadmin-samp-wrapper
*/

#if defined NEURO_ADMIN_INCLUDED
	#endinput
#endif
#define NEURO_ADMIN_INCLUDED

// Library
#include <a_http> // Source: https://sa-mp.com

// Configuration
#define MAIN_NEURO_NETWORK  "dev.hyaxe.cloud:25000"
#define NEURO_API_KEY       "demo"

// Register callbacks
forward OnNeuroResponse(response_status, const response[], playerid);

// Response types
enum {
    INVALID_RESPONSE,
    NOT_FOUND_ERROR,
    INTERNAL_SERVER_ERROR,
    DATASET_NOT_FOUND,
    RESPONSE_NOT_FOUND,
    VALID_RESPONSE,
    VALID_CENSORSHIP,
    INVALID_CENSORSHIP
}

// Get an answer to a question
stock GetNeuroResponse(const text[], const dataset[] = "hyaxe", playerid = INVALID_PLAYER_ID)
{
    new url[128];
    format(url, sizeof(url), ""MAIN_NEURO_NETWORK"/"NEURO_API_KEY"/get/response/%s", dataset);
    HTTP(playerid, HTTP_POST, url, text, "neuroadmin_GetResponse");
    return 1;
}

// Check if a censorship filter is violated
stock GetNeuroCensorshipCheck(const text[], const dataset[] = "hyaxe", playerid = INVALID_PLAYER_ID)
{
    new url[128];
    format(url, sizeof(url), ""MAIN_NEURO_NETWORK"/"NEURO_API_KEY"/get/censorship/%s", dataset);
    HTTP(playerid, HTTP_POST, url, text, "neuroadmin_GetResponse");
    return 1;
}

// Parse response
forward neuroadmin_GetResponse(index, response_code, const data[]);
public neuroadmin_GetResponse(index, response_code, const data[])
{
    if (response_code > 15) response_code = INVALID_RESPONSE;
    OnNeuroResponse(response_code, data, index);
    return 1;
}