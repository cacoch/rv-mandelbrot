#include<stdio.h>
#include <stdlib.h>
#include <complex.h>


//#define HOST '127.0.0.1'

//define PORT  int(sys.argv[1])

//print("Starting server on %s:%s" % (HOST, PORT))


int c, max_iter;

int  mandelbrot(int c, int max_iter) {
	int z = 0;
	int n = 0;
	while (abs(z) <= 2 &&  n < max_iter){
		z = z*z + c ;
		n += 1;
	}

	return n;
}

int main () {
	int x;
	//x = mandelbrot(1,3);
double complex z1 = 1.0 + 3.0 * I;
double complex z2 = 1.0 - 4.0 * I;
	
double complex zx;
       zx = z1 + z2;
       printf("1.0 + 3.0 * I");
printf("1.0 - 4.0 * I");

printf("real part of Z1 = %.2f \n", creal(zx));
printf("real part of Z1 = %.2f \n", cimag(zx));


	return 1;

}
/*
# Get the amount of iterations for one pixel
def get_calculations(current_x, current_y, total_x, total_y, re_start, re_end, im_start, im_end, max_iter):

	first_number = re_start + (current_x / total_x) * (re_end - re_start)
	second_number = im_start + (current_y / total_y) * (im_end - im_start)

	c = complex(first_number, second_number)

	calculated = mandelbrot(c, max_iter)
	return calculated

def generate(start_x, start_y, end_x, end_y, total_x, total_y, re_start, re_end, im_start, im_end, max_iter):

	xes = []

	for x in range(start_x, end_x):
		yes = []
		for y in range(start_y, end_y):

			calculations = get_calculations(x, y, total_x, total_y, re_start, re_end, im_start, im_end, max_iter)
			yes.append(calculations)

		xes.append(yes)

	return xes


def generate_calculations(parameters):

	start_x, start_y = parameters["start_x"], parameters["start_y"]
	end_x, end_y = parameters["end_x"], parameters["end_y"]

	total_x, total_y = parameters["total_x"], parameters["total_y"]

	max_iter = parameters["max_iter"]

	re_start = parameters["re_start"]
	re_end = parameters["re_end"]

	im_start = parameters["im_start"]
	im_end = parameters["im_end"]

	full = generate(start_x, start_y, end_x, end_y, total_x, total_y, re_start, re_end, im_start, im_end, max_iter)

	return full

def send_the_whole_thing(bytes_to_send, length, conn):

	ok = False

	total_bytes = length
	total_sent = 0

	# Send 60k bytes per package
	start = 0
	stop = 60000

	# Start by sending a package containing the length
	length_bytes = length.to_bytes(5, 'big')
	
	print("Sending %s size length package %s" % (len(length_bytes), length_bytes))
	
	conn.send(length_bytes)

	# Keep sending as long as we have not sent it all
	while total_sent < total_bytes:

		data_to_send = bytes_to_send[start:stop]
		sent = conn.send(data_to_send)

		print("Sent [%s-%s] (total %s)" % (start, stop, sent))

		if sent == 0:
			print("Connection broken")

		start += sent
		stop += sent

		total_sent += sent


	if total_sent >= total_bytes:
		ok = True

	return ok

# Start the server
running = True

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:

	s.bind((HOST, PORT))
	s.listen()

	while running:
			
		conn, addr = s.accept()
		
		with conn:
				
			print("connected by", addr)

			while True:

				try:
					data = conn.recv(1024)
				except ConnectionResetError:
					break

				if not data:
					break

				# Receive a json message with parameters,
				# generate the calculations for the specified dimensions,
				# serialize to json and sent back the json as bytes

				as_json_string = data.decode('utf-8')

				parameters = json.loads(as_json_string)
				

				print("Received parameters: %s" % parameters)

				result = generate_calculations(parameters)

				as_json = json.dumps(result).encode('utf-8')
				

				print("The result is %s bytes long, will try to send 60k bytes each" % len(as_json))

				result = send_the_whole_thing(as_json, len(as_json), conn)

				if result:
					print("Successfully sent the returning message")
				else:
					print("Failed to send the returning message")
*/
