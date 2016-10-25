CXX = g++
CXXINCDIRS = -I. -I./ext/glui/include
CXXLINKLIBRARIES = -L./ext/glui/lib -lglut -lGL -lGLU -lglui
SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./include
BINDIR = ./bin
EXE = $(BINDIR)/Brushwork
CXXFLAGS += $(CXXINCDIRS)
CXXFLAGS += -std=c++11

SRC_CXX = $(wildcard $(SRCDIR)/*.cc)
OBJECTS_CXX = $(patsubst $(SRCDIR)/%.cc, $(OBJDIR)/%.o, $(SRC_CXX))

.PHONY: clean all

all: $(EXE)

sure: 
	echo $(CXXFLAGS)

$(EXE): $(OBJECTS_CXX) | $(BINDIR)
	$(CXX) -o $@ $^ $(CXXLINKLIBRARIES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(INCDIR)/%.h | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cc | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean: 
	rm -rf $(OBJDIR) $(BINDIR)
