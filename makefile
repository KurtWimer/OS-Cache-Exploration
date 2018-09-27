all:
	make bcache
	make mcache
	make ecache
bcache:
	g++ -std=c++11 -o bcache.cpp implementaion/* implementation/cacheLocs/cache_b.cpp 
mcache:
	g++ -std=c++11 -o mcache.cpp implementaion/* implementation/cacheLocs/cache_m.cpp 
ecache:
	g++ -std=c++11 -o bcache.cpp implementaion/* implementation/cacheLocs/cache_e.cpp 
