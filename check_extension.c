

void check_args(int argc, char **argv)
{
	char *ext;
	
	if (argc == 2)
	{
		if((ext = strrchr(argv[1],'.')) != NULL ) 
		{
			if(strcmp(ext,".ber") == 0) 
			{
			     //read map
			}
		}
		printf("Invalid map extension, it should be a .ber file");
	}
	else
		printf("Only the first parameter will be used, it should be a map") 
}
