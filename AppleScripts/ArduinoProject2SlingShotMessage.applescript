(*define error method*)
on report(ErrorPayload)
	tell application "iTerm"
		create window with default profile
	end tell
	tell application "System Events"
		keystroke "push " & ErrorPayload --using {option down, command down}
		keystroke return
		delay 1
		keystroke "w" using {command down}
	end tell
end report


using terms from application "Messages"
	on message received theMessage from theBuddy for theChat with eventDescription
		try
			set theHandle to handle of theBuddy
			set theContent to eventDescription
			set payload to theHandle & "," & theContent
			
			#Create a push request and send the message content
			display notification "DOING JOB"
			set postRequest to "curl -X POST -H \"Content-Type: application/json\" -d '{\"value1\":\"" & theHandle & "\",\"value2\":\"" & theContent & "\"}' https://maker.ifttt.com/trigger/toArduinoWithPayload/with/key/bLMBpfOKL5alWnYd1MMij3"
			
			tell application "iTerm"
				create window with default profile
			end tell
			
			tell application "System Events"
				keystroke postRequest
				keystroke return
				delay 1
				keystroke "w" using {command down}
			end tell
			
		on error errorMessage number errorNumber
			report("errorMessage: " & errorMessage & ", errorNumber: " & errorNumber)
		end try
		
	end message received
	
	
	# The following are unused but need to be defined to avoid an error
	
	on active chat message received from theBuddy for theChat with eventDescription
	end active chat message received
	
	on message sent theMessage with eventDescription
		
	end message sent
	
	on chat room message received with eventDescription
		#	say eventDescription
	end chat room message received
	
	on addressed message received theMessage from theBuddy for theChat with eventDescription
		#		say eventDescription
	end addressed message received
	
	on received text invitation with eventDescription
		#		say eventDescription
	end received text invitation
	
	on received audio invitation theText from theBuddy for theChat with eventDescription
		#		say eventDescription
	end received audio invitation
	
	on received video invitation theText from theBuddy for theChat with eventDescription
		#		say eventDescription
	end received video invitation
	
	on «event ichthe15» given «class hepr»:theBuddy, «class hect»:theChat, «class heed»:eventDescription
		#		say eventDescription
	end «event ichthe15»
	
	on buddy authorization requested with eventDescription
		#		say eventDescription
	end buddy authorization requested
	
	on addressed chat room message received with eventDescription
		#		say eventDescription
	end addressed chat room message received
	
	on «event ichthe16» given «class heed»:eventDescription
		#		say eventDescription
	end «event ichthe16»
	
	on login finished with eventDescription
	end login finished
	
	on logout finished with eventDescription
	end logout finished
	
	on buddy became available with eventDescription
	end buddy became available
	
	on buddy became unavailable with eventDescription
	end buddy became unavailable
	
	on received file transfer invitation theFileTransfer with eventDescription
	end received file transfer invitation
	
	on av chat started with eventDescription
	end av chat started
	
	on av chat ended with eventDescription
	end av chat ended
	
	on completed file transfer with eventDescription
	end completed file transfer
	
end using terms from