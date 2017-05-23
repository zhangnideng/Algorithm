#/bin/bash

cd ..

rm -fr build
echo "build has been removed"
echo

mkdir build
cd build

cmake ../cmake/
make

#echo
#make install

./test
