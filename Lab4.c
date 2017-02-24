#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100

char file_name[10];
int i,j,no_of_samples,max_sample_size;
int samples[MAX];
int n_flag=0,s_flag=0,o_flag=0,r_flag=0,h_flag=0,help_flag=0,max_value=0,S_flag=0,C_flag=0,N_flag=0;
float offset_value,scale_factor,average_value;
float offset_samples[MAX],scaled_samples[MAX],centre_samples[MAX],normal_samples[MAX];

int help()
{
	help_flag=1;
	printf("\n\n\t\t\t---HELP---\n\nThe options/parameters are \n-n: File number (value needed)\n-o: offset value (value needed)\n-s: scale factor (value needed)\n-r: Rename files (name needed)\n-h: Help (display how the program should be called, including the different input options)\n");  
	printf("\nsome examples calls are \n./My_Lab4_program -n 3 -o 2.5 \n./My_Lab4_program -s 1.7 -n 10 \n./My_Lab4_program -n 2 -r NewName \n./My_Lab4_program -n 2 -r NewName -s 3 \n./My_Lab4_program -h \n\n");
	return 0;
}

int maximum()
{
	max_value=samples[0];
	for(i=0;i<no_of_samples;i++)
	{
		if(max_value<samples[i])
		{
			max_value=samples[i];
		}
	}
	return 0;
}

int average()
{
	average_value=0;
	for(i=0;i<no_of_samples;i++)
	{
		average_value=average_value+samples[i];
	}
	average_value=average_value/no_of_samples;
	return 0;
}

int invalid_function()
{
	if(!help_flag)
	{
		for(i=0;i<100;i++)
		{	
			printf("*");
		}
		printf("\n\n\t\tinvalid input\nplease check the help options to correct your input");
		help();
		for(i=0;i<100;i++)
		{
			printf("*");
		}
	}
	return 0;
}
	
int read_file()
{
	char in_file_name[20]="Raw_data_";
	FILE *input_file;
	if(!atoi(file_name))
	{
		invalid_function();
	}
	else
	{
		if(atoi(file_name)<10)
		{
			strcat(in_file_name,"0");
		}
		strcat(in_file_name,file_name);
		strcat(in_file_name,".txt");
		input_file=fopen(in_file_name,"r+");
		fscanf(input_file,"%d",&no_of_samples);
		fscanf(input_file,"%d",&max_sample_size);
		for(j=0;j<no_of_samples;j++)
		{
			fscanf(input_file,"%d",&samples[j]);
		}
		fclose(input_file);
		average();
		maximum();
	}
	return 0;
}

int offset_function(char* value)
{
	char offset_file_name[20]="Offset_data_";
	FILE *offset_file;
	if(atof(value)==0)
	{
		invalid_function();
	}
	else
	{
		offset_value=atof(value); 
		for(i=0;i<no_of_samples;i++)
		{
			offset_samples[i]=samples[i]+offset_value;
		}
		if(atoi(file_name)<10)
		{
			strcat(offset_file_name,"0");
		}
		strcat(offset_file_name,file_name);
		strcat(offset_file_name,".txt");
		offset_file=fopen(offset_file_name,"w+");
		fprintf(offset_file,"%d %.4f",no_of_samples,offset_value);
		for(i=0;i<no_of_samples;i++)
		{
			fprintf(offset_file,"\n%.4f",offset_samples[i]);
		}
		fclose(offset_file);
	}
}

int scale_function(char* value)
{
	char scaled_file_name[20]="Scaled_data_";
	FILE *scaled_file;
	if(atof(value)==0)
	{
		invalid_function();
	}
	else
	{
		scale_factor=atof(value); 
		for(i=0;i<no_of_samples;i++)
		{
			scaled_samples[i]=samples[i]*scale_factor;
		}
		if(atoi(file_name)<10)
		{
			strcat(scaled_file_name,"0");
		}
		strcat(scaled_file_name,file_name);
		strcat(scaled_file_name,".txt");
		scaled_file=fopen(scaled_file_name,"w+");
		fprintf(scaled_file,"%d %.4f",no_of_samples,scale_factor);
		for(i=0;i<no_of_samples;i++)
		{
			fprintf(scaled_file,"\n%.4f",scaled_samples[i]);
		}
		fclose(scaled_file);
	}
}

int create_copy(char* new_name)
{
	char rename_file_name[20];
	FILE *rename_file;
	strcpy(rename_file_name,new_name);
	strcat(rename_file_name,".txt");
	rename_file=fopen(rename_file_name,"w+");
	fprintf(rename_file,"%d %d",no_of_samples,max_sample_size);
	for(j=0;j<no_of_samples;j++)
	{
		fprintf(rename_file,"\n%d",samples[j]);
	}
	fclose(rename_file);
	return 0;
}

int stat_function()
{
	char stat_file_name[50]="Statistics_data_";
	FILE *stat_file;
	average();
	maximum();
	if(atoi(file_name)<10)
	{
		strcat(stat_file_name,"0");
	}
	strcat(stat_file_name,file_name);
	strcat(stat_file_name,".txt");
	stat_file=fopen(stat_file_name,"w+");
	fprintf(stat_file,"%.4f %d",average_value,max_value);
	fclose(stat_file);
}

int centre_function(float value)
{
	char centre_file_name[50]="Centered_data_";
	FILE *centre_file;
	for(i=0;i<no_of_samples;i++)
	{
		centre_samples[i]=samples[i]-value;
	}
	if(atoi(file_name)<10)
	{
		strcat(centre_file_name,"0");
	}
	strcat(centre_file_name,file_name);
	strcat(centre_file_name,".txt");
	centre_file=fopen(centre_file_name,"w+");
	fprintf(centre_file,"%d %.4f",no_of_samples,value);
	for(i=0;i<no_of_samples;i++)
	{
		fprintf(centre_file,"\n%.4f",centre_samples[i]);
	}
	fclose(centre_file);
}

int normal_function(int value)
{
	char normal_file_name[50]="Normalized_data_";
	FILE *normal_file;
	for(i=0;i<no_of_samples;i++)
	{
		normal_samples[i]=((float)samples[i])/((float)value);
	}
	if(atoi(file_name)<10)
	{
		strcat(normal_file_name,"0");
	}
	strcat(normal_file_name,file_name);
	strcat(normal_file_name,".txt");
	normal_file=fopen(normal_file_name,"w+");
	fprintf(normal_file,"%d %d",no_of_samples,value);
	for(i=0;i<no_of_samples;i++)
	{
		fprintf(normal_file,"\n%.4f",normal_samples[i]);
	}
	fclose(normal_file);
}

int main(int argc, char* argv[])
{
	if(argc==1)
	{
		invalid_function();
	}
	else
	{
		for(i=1;i<argc;i=i+2)
		{
			switch(argv[i][1])
			{
				case 'n' : n_flag=i;break;
				case 'o' : o_flag=i;break;
				case 's' : s_flag=i;break;
				case 'r' : r_flag=i;break;
				case 'h' : h_flag=i;break;
				case 'S' : S_flag=i;i--;break;
				case 'C' : C_flag=i;i--;break;
				case 'N' : N_flag=i;i--;break;
				default  : invalid_function();
			}
		}
		if(h_flag)
		{
			if(!help_flag)
			{
				for(i=0;i<100;i++)
				{
					printf("*");
				}
				help();
				for(i=0;i<100;i++)
				{
				printf("*");
				}	
			}
		}
		else
		{
			if(!n_flag)
			{
				invalid_function();
			}
			else
			{
				if(!atoi(argv[n_flag+1]))
				{
					invalid_function();
				}
				else
				{
					strcpy(file_name,argv[n_flag+1]);
					read_file();
				}
				if(s_flag)
				{
					scale_function(argv[s_flag+1]);
				}
				if(o_flag)
				{
					offset_function(argv[o_flag+1]);
				}
				if(r_flag)
				{
					create_copy(argv[r_flag+1]);
				}
				if(C_flag)
				{       average();
					centre_function(average_value);
				}
				if(N_flag)
				{       maximum();
					normal_function(max_value);
				}
				if(S_flag)
				{       average();
                                        maximum();
					stat_function();
				}				
			}
		}
	}
	return 0;
}