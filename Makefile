CXX=g++
CXXFLAGS=-Wall -pedantic
LD=g++
LDFLAGS=-Wall -pedantic

TARGET=Game.out

#The Directories
OBJDIR=obj
SRCDIR=src


SOURCES= $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS= $(SOURCES:%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJECTS:%.o=%.d)

-include $(DEP)

#Compile
$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(TARGET)


#build objects and dependencies
$(OBJDIR)/%.o: %.cpp
	@mkdir -p '$(@D)'
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ 


#Possibly does not work xD
.PHONY: clean 
#Clean
clean:
	@rm -rf $(OBJDIR)
