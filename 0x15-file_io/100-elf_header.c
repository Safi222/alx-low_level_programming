#include "main.h"

/**
 * handle_error - Print the errors to the stderror with exit code 98
 * @error_msg: The message to write to stderror
 *
 * Return: Void
 */
void handle_error(char *error_msg)
{
	dprintf(STDERR_FILENO, "%s\n", error_msg);
	exit(98);
}


/**
 * check_elf - Check if the file is an ELF file
 * @e_ident: An array holding the needed data to check the file
 *
 * Return: void
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != 0x7f ||
	    e_ident[EI_MAG1] != 'E' ||
	    e_ident[EI_MAG2] != 'L' ||
	    e_ident[EI_MAG3] != 'F')
	{
		handle_error("Error: Not an ELF file");
	}

}



/**
 * close_elf - Close an elf file
 * @fd: The file descriptor of the file we need to close
 *
 * Return: void
 */
void close_elf(int fd)
{
	if (close(fd) == -1)
		handle_error("Cannot close the fd file");
}


/**
 * print_magic - Print the magic numbers of an ELF file
 * @e_ident: An array holding the magic numbers
 *
 * Return: void
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * print_class - Print the class of the file
 * @e_ident: An array holding the class type
 *
 * Return: void
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	}
}


/**
 * print_data - Print the endianisness of the file
 * @e_ident: An array holding the endianisness of the file
 *
 * Return: void
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);

	}
}



/**
 * print_version - Print the version number of the ELF specification
 * @e_ident: An array holding the version number
 *
 * Return: void
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");

	}
}


/**
 * print_osabi - Print the operating system and ABI to which the object
 *		 is targeted
 * @e_ident: An array holding the OS/ABI
 *
 * Return: void
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Stand-alone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);

	}
}



/**
 * print_abi_version - Print the ABI to which the object is targeted
 * @e_ident: An array holding the ABI version
 *
 * Return: void
 */
void print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}


/**
 * print_type - Print the type of the elf file
 * @e_type: A value that will be compared with one of the
 *	    macros to identify the type
 * @e_ident: An array holding the needed data
 *
 * Return: void
 */
void print_type(uint16_t e_type, unsigned char *e_ident)
{

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (none)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}


/**
 * print_entry_point - Print the entry point address of the file
 * @e_ident: An array holding the needed data
 * @e_entry: The virtual address to which the system first transfers control,
 *	     thus starting the process.
 *	     If the file has no associated entry point, this member holds zero.
 *
 * Return: void
 */
void print_entry_point(Elf64_Addr e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}



/**
 * main - Display the information contained in the ELF header
 * @argc: The number of the arguments passed to the function
 * @argv: A pointer to the array f arguments passed to the function
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int o, r;
	Elf64_Ehdr *header;

	if (argc < 2)
		handle_error("You should pass only one file no more no less");

	o = open(argv[1], O_RDONLY);

	if (o == -1)
		handle_error("Cannot open the file");

	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
	{
		close_elf(o);
		handle_error("Can't read the file");
	}

	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		handle_error("Can't read the file");
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi_version(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry_point(header->e_entry, header->e_ident);
	free(header);
	close_elf(o);

	return (0);
}
