SUBDIRS = src/arrays/quick-sort \
			 src/linked-lists/reverse-list \
			 src/linked-lists/sorted-merge \

.PHONY: subdirs $(SUBDIRS) clean

subdirs: $(SUBDIRS)

$(SUBDIRS):
	        $(MAKE) -C $@

include Makefile.inc

#TODO: Improve to clean recursively
#TODO: Improve to clean object files
clean:
	rm -rf $(BUILD_DIRNAME)
