OBJECT=libsimple.so
URI=http://colin.kinlo.ch/lv2/simple/
cat manifest.ttl.in | sed "s/@OBJECT@/${OBJECT}/g" > manifest.ttl
make
