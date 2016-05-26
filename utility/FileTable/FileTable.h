#ifndef FILETABLE_H
#define FILETABLE_H

#include "../HashTable/HashTable.h"
#include "../Queue/Queue.h"

typedef struct FileTable FileTable;

FileTable* filetable_new();
void filetable_destroy(FileTable* filetable);

// Serializes the provided filesystem to save it to disk or send over the network.
//	filetable  : (not claimed) The filetable to serialize
//	data	   : (not claimed) The serialized data
//	length	   : (not claimed) The length of the serialized data
void filetable_serialize(FileTable* filetable, char** data, int* length);

// Takes some data and deserializes it into a filetable.
//	data      : (not claimed) The data to deserialize
//  bytesRead : (not claimed) The number of bytes read by the deserializer
//	ret	      : (not claimed) The returned filetable
FileTable* filetable_deserialize(char* data, int* bytesRead);

Queue* filetable_get_peers_have_file(FileTable* filetable, char* path);
void   filetable_set_peer_has_file(FileTable* filetable, char* path, int id);
void   filetable_remove_peer(FileTable* filetable, int id);
void   filetable_clear_file(FileTable* filetable, char* path);

#endif