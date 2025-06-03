#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main(){
	// Creating a HTTP Server
	// Step 1: Create a socket and listen for new connections.
	// Step 2: Accept incoming client connections.
	// Step 3: Receive messages, process them, and send some responses to the clients.
	// Step 4: Close the connection.
	
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverAddress;

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 5);
	
	while (true){
		int clientSocket = accept(serverSocket, nullptr, nullptr);

		char buffer[1024] = {0};

		recv(clientSocket, buffer, sizeof(buffer), 0);

		cout << "Message from client: " << buffer << endl;

		close(clientSocket);
	}

	close(serverSocket);
	return 0;
}
