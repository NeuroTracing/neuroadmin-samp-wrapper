/*
* neuroadmin-samp-wrapper (Example)
* Wrapper to use the NeuroAdmin API from Pawn (SAMP)
* GitHub: https://github.com/NeuroTracing/neuroadmin-samp-wrapper
*/

#include <a_samp>
#include <neuroadmin>

main()
{
	// Get an answer to a question
	GetNeuroResponse("como abro el inventario?");

	// Check if a censorship filter is violated
	GetNeuroCensorshipCheck("hijos de la gran puta");
}

public OnNeuroResponse(response_status, const response[], playerid)
{
	if (response_status == INVALID_RESPONSE) return 0;

	switch(response_status)
	{
		case VALID_RESPONSE:
		{
			printf("Response: %s", response);
		}
		case VALID_CENSORSHIP:
		{
			printf("The text is considered spam: %s", response);
		}
	}
	return 1;
}