all: word_mastermind


word_mastermind:
	g++ -o word_mastermind main.cpp -l curlpp -lcurl


clean: 
	rm -rf word_mastermind
